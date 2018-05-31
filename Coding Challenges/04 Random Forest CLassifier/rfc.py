#Importing the libraries
import numpy as np
import pandas as pd
import csv
import matplotlib.pyplot as plt
from random import randrange,seed
from math import sqrt
from matplotlib import style

style.use('ggplot')

#Importing the dataset
data = pd.read_csv('german_credit_data.csv',header=None).values.tolist()
#Since there is no categorical data so no need of Label Encoding

#Accuracy 
def accuracy_count(y_true,y_pred):
    accuracy = 0
    for i in range(len(y_true)):
        if y_true[i] == y_pred[i]:
            accuracy += 1
    return accuracy / len(y_true) * 100.0

#Returns the dictionary consisting of the count of the various classes existing in the data.
def class_count(data):
    #Last column is the label of the dataset
    labels = [row[-1] for row in data]

    count = {}          #Count Dictionary
    for label in labels:
        if label not in count:
            count[label] = 1
        else:
            count[label] += 1
    return count

#Calculates the gini impurity in the data
def gini_impurity(data):
    #Refer to the wikipedia page of Decision Tree for more info.
    #Formula : 1 - (p[1]**2 + p[2]**2 + p[3]**2 + p[4]**2 + .....)
    #where  p[i] is probability of the ith label in the data
    labels_cnt = class_count(data)
    rows = len(data)
    impurity = 1
    for label in labels_cnt:
        impurity = impurity - (labels_cnt[label] / rows)**2
    return impurity

#Calculation of the information gain to determine the better splitting feature
def info_gain(left_child,right_child,gini_parent):
    #Formula = gini_parent - (cumulative gini of both childs)
    #Cumulative gini = p * gini(left_child) + (1-p) * gini(right_child) ---p is the proportion of left_child in total
    p = len(left_child) / (len(left_child) + len(right_child))
    #One with the highest information gain would be considered as the best alternative
    return gini_parent - p * gini_impurity(left_child) - (1-p) * gini_impurity(right_child)

#Cross Validation Split
def cross_validation_split(dataset,n_folds):
    #Divide the dataset in n_folds groups.
    n_samples_per_fold = int(len(dataset)/n_folds)
    dataset_split = []
    
    for i in range(n_folds):
        fold = []
        while len(fold) < n_samples_per_fold and dataset!=[]:
            indx = randrange(len(dataset))
            fold.append(dataset.pop(indx))
        dataset_split.append(fold)
    return dataset_split

#Check whether the input sample matches with the feature of split
class Question:
    def __init__(self,col,f_val):
        self.col = col
        self.f_val = f_val
    
    def match(self,row):
        #Handling the Numeric Data
        return row[self.col] >= self.f_val
    
#Partition the dataset based on the groups
def partition(dataset,question):
    true_rows , false_rows = list(),list() 
    for row in dataset:
        if question.match(row):
            true_rows.append(row)
        else:
            false_rows.append(row)
    return true_rows , false_rows
        
def best_split(data,n_features):
    gini_parent = gini_impurity(data)
    best_gain = 0
    best_ques = None
    features = []
    while len(features) < n_features:
        indx = randrange(len(data[0])-1)
        if indx not in features:
            features.append(indx)
    for feature in features:
        unique_features = list(set([row[feature] for row in data]))
        for unique in unique_features:
            question = Question(feature,unique)
            true_rows,false_rows = partition(data,question)
            if len(true_rows)==0 or len(false_rows)==0:
                pass
            gain = info_gain(true_rows,false_rows,gini_parent)
            #Comparing with the best gain so far
            if gain >= best_gain:
                best_gain,best_ques = gain,question
    return best_gain,best_ques

def build_tree(data,max_depth,min_size,n_features,depth):
    if len(data) <= min_size or depth > max_depth:
        return Leaf(data)
    gain , ques = best_split(data,n_features)
    if gain == 0:
        return Leaf(data)
    true_rows,false_rows = partition(data,ques)
    right_branch = build_tree(true_rows,max_depth,min_size,n_features,depth+1)
    left_branch = build_tree(false_rows,max_depth,min_size,n_features,depth+1)
    return DecisionNode(ques,left_branch,right_branch)

#Connecting the parent node with its child
class DecisionNode:
    def __init__(self,question,left_branch,right_branch):
        self.question = question
        self.left_branch = left_branch
        self.right_branch = right_branch

#Representation of the leaf node
class Leaf:
    def __init__(self,rows):
        self.predictions = class_count(rows)

#Classify the test value
def classify(node,test):
    if isinstance(node,Leaf):
        return node.predictions
    if node.question.match(test):
        return classify(node.right_branch,test)
    else:
        return classify(node.left_branch,test)

#Creating the random subsample with replacement        
def shuffle(training_data,ratio):
    sample = []
    size = int(len(training_data) * ratio)
    while len(sample) < size:
        indx = randrange(len(training_data))
        sample.append(training_data[indx])
    return sample

#Returns the overall result by combining all the trees
def bagged_tree(row,trees):
    predictions = {}
    for tree in trees:
        predict = classify(tree,row)
        for prop in predict:
            if prop in predictions:
                predictions[prop] += predict[prop]
            else:
                predictions[prop] = predict[prop]
    max_indx = -1
    for i in predictions:
        if max_indx == -1:
            max_indx = i
        else:
            if predictions[max_indx] < predictions[i]:
                max_indx = i
    return max_indx

#It maintains the record of all the trees 
def random_forest(training_data,test_data,n_trees,max_depth,min_size,ratio,n_features):
    trees = []
    for i in range(n_trees):
        subsample = shuffle(training_data,ratio)
        trees.append(build_tree(subsample,max_depth,min_size,n_features,1))
    predictions = [bagged_tree(row,trees) for row in test_data]
    return predictions

#Evaluation Procedure
def evaluate_algorithm(data,n_trees,max_depth,min_size,ratio,n_features,n_folds):
    folds = cross_validation_split(list(data),n_folds)
    scores = []
    for fold in folds:
        training_set = list(folds)
        training_set.remove(fold)
        training_set = sum(training_set,[])
        test_set = []
        for row in fold:
            row_copy = list(row)
            test_set.append(row_copy)
            row_copy[-1] = None
        prediction = random_forest(training_set,test_set,n_trees,max_depth,min_size,ratio,n_features)
        actual = [row[-1] for row in fold]
        score = accuracy_count(actual,prediction)
        scores.append(score)
    #print(scores)
    #print('Average Accuracy:',sum(scores)/len(scores))
    return (sum(scores)/len(scores))
    
#Setting the seed to get 
seed(1)

# Evaluate Algorithm
n_folds = 5
max_depth = 10
min_size = 1
ratio = 1.0
n_features = int(sqrt(len(data[0])-1))
scores = []

for n_trees in range(1,100,8):
    score = evaluate_algorithm(data,n_trees,max_depth,min_size,ratio,n_features,n_folds)
    print('Accuracy when there are',n_trees,' trees is:',score)
    scores.append(scores)

#Visualising the accuracies with the increasing number of trees
plt.scatter(list(range(1,100,8)),scores,color='r',linewidth=5)
plt.plot(list(range(1,100,8)),scores,color='c')
plt.title('Random Forest Classifier')
plt.xlabel('Number of trees')
plt.ylabel('Accuracy')
plt.xlim(0,100)
plt.ylim(60,100)
plt.show()