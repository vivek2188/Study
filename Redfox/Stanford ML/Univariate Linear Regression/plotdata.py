import matplotlib.pyplot as plt

def plotdata(X,y):
    plt.scatter(X,y,color='red',s=15,marker='x')
    plt.xlabel('Population of City in 10,000s')     
    plt.ylabel('Profit in $10,000s')
    plt.title('Scatter Plot of Training data')
    plt.show()