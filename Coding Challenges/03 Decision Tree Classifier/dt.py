#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

training_data = [
    ['Green', 3, 'Apple'],
    ['Yellow', 3, 'Apple'],
    ['Red', 1, 'Grape'],
    ['Red', 1, 'Grape'],
    ['Yellow', 3, 'Lemon'],
]

header = ['Color','Diameter','Label']

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

#Class Decision Tree
class DecisionTreeClassifier:
    def __init__(self):
        self.tree = None
    
    #Check whether the input sample matches with the feature of split
    class Question:
        def __init__(self,feature,feature_val):
            self.feature = feature
            self.feature_val = feature_val
        
        def match(self,row):
            #Handling the Numeric Data
            if isinstance(row[self.feature],int) or isinstance(row[self.feature],float):
                return row[self.feature] >= self.feature_val
            #Handling the Categorical Data
            else:
                return row[self.feature] == self.feature_val
    
    #Partitions the data based on the feature split which is contained in the "question"
    def partition(self,data,question):
        #It partitions the whole data into the rows which satisty the conditions and those who don't
        true_rows = []
        false_rows = []
        for row in data:
            if question.match(row):
                true_rows.append(row)
            else:
                false_rows.append(row)
        return true_rows , false_rows
    
    #Finding the best point of split
    def best_split(self,data):
        rows,features = np.array(data).shape
        features -= 1     #Excluding the label column
        
        gini_parent = gini_impurity(data)
        best_gain = 0
        best_ques = None
        for feature in range(features):
            unique_features = list(set([row[feature] for row in data]))
            for unique in unique_features:
                question = self.Question(feature,unique)
                true_rows,false_rows = self.partition(data,question)
                if len(true_rows)==0 or len(false_rows)==0:
                    pass
                gain = info_gain(true_rows,false_rows,gini_parent)
                #Comparing with the best gain so far
                if gain >= best_gain:
                    best_gain,best_ques = gain,question
        return best_gain,best_ques
    
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
    
    #Building the TREE
    def build_tree(self,data):
        gain , ques = self.best_split(data)
        if gain == 0:
            return self.Leaf(data)
        true_rows,false_rows = self.partition(data,ques)
        right_branch = self.build_tree(true_rows)
        left_branch = self.build_tree(false_rows)
        return self.DecisionNode(ques,left_branch,right_branch)
    
    #Printing the tree
    def print_tree(self,node,spacing=""):
        if isinstance(node,self.Leaf):
            print(spacing,'Predict: ',node.predictions)
            return
        #Print the questions
        ques = node.question
        if isinstance(ques.feature_val,str):
            print(spacing,"Is",header[ques.feature],"==",ques.feature_val,"?")
        else:
            print(spacing,"Is",header[ques.feature],">=",ques.feature_val,"?")
        #True branch:
        print(spacing,'->True:')
        self.print_tree(node.right_branch,spacing=spacing+"  ")
        #False branch:
        print(spacing,'->False:')
        self.print_tree(node.left_branch,spacing=spacing+"  ")
        
    #Classify the test value
    def classify(self,node,test):
        if isinstance(node,self.Leaf):
            predictions = node.predictions
            total = sum(list(predictions.values()))
            for predict in predictions:
                predictions[predict] *= (100/total) 
            print('Predicted:',predictions)
            return
        if node.question.match(test):
            return self.classify(node.right_branch,test)
        else:
            return self.classify(node.left_branch,test)
        
#Creating the object of the class DecisionTreeClassifier
dt = DecisionTreeClassifier()
dt.tree = dt.build_tree(training_data)

#Printing the tree
dt.print_tree(dt.tree)

#Testing data
testing_data = [
    ['Green', 3, 'Apple'],
    ['Yellow', 4, 'Apple'],
    ['Red', 2, 'Grape'],
    ['Red', 1, 'Grape'],
    ['Yellow', 3, 'Lemon'],
]
print("----------------Predicted Results:-------------------")
for test in testing_data:
    print("True Value:",test[-1])
    dt.classify(dt.tree,test)
    print("")