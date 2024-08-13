import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
import time


data = pd.read_csv('dataset.csv', header=None)
X = data.iloc[:, :-1]  
y = data.iloc[:, -1]   

while True:
    try:
        train_size = int(input("Enter the training set (number of samples): "))
        test_size = int(input("Enter the test set (number of samples): "))
        
        if train_size > 0 and test_size > 0 and (train_size + test_size) <= len(X):
            break
    except ValueError:
        print("Invalid input.")

X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=train_size, test_size=test_size, random_state=42)


models = {
    "Logistic Regression": LogisticRegression(max_iter=1000),
    "Random Forest": RandomForestClassifier(),
    "Support Vector Machine": SVC(),
    "K-Nearest Neighbors": KNeighborsClassifier()
}

for name, model in models.items():
    t1 = time.time()
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred) * 100
    print(f"{name} Accuracy: {accuracy:.2f}%")
    t2 = time.time()
    print(f'Elapsed time: {t2 - t1:.2f} seconds')
