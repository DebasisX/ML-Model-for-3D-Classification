Hyperspace Classification:
--------------------------
Test 0:
-------
K-Nearest Neighbors Accuracy: 98.70%
Elapsed time: 0.05 seconds

Model Accuracy: 99.40%
Elapsed time: 0.0019805431365966797 seconds
(1000 TEST and TRAIN)

3D Classification:
------------------
Test 1:
-------
Popular Classification Models: (Trained and Tested on 50k)
------------------------------
Logistic Regression Accuracy: 99.3%
Elapsed time: 0.01355433464050293 seconds
Random Forest Accuracy: 99.44%
Elapsed time: 0.32317042350769043 seconds
Support Vector Machine Accuracy: 99.3%
Elapsed time: 0.03011775016784668 seconds
K-Nearest Neighbors Accuracy: 99.44%
Elapsed time: 0.18068432807922363 seconds

My Model: (Trained and Tested on 50k)
---------
Model Trained
Model Accuracy: 99.31%
Elapsed time: 0.005217075347900391 seconds

Test 2:
-------
Enter the training set size (number of samples): 1000
Enter the test set size (number of samples): 1000
Logistic Regression Accuracy: 99.80%
Elapsed time: 0.01 seconds
Random Forest Accuracy: 99.70%
Elapsed time: 0.12 seconds
Support Vector Machine Accuracy: 99.50%
Elapsed time: 0.01 seconds
K-Nearest Neighbors Accuracy: 99.30%
Elapsed time: 0.04 seconds

Enter number of training samples: 1000
Enter number of test samples: 1000
Enter number of features: 3
Model Trained
Model Accuracy: 99.70%
Elapsed time: 0.001699686050415039 seconds

TEST 3:
-------
Iris Dataset:
-------------

(Incinerate-X) debasis@Debasis:~/project/temp$ python3 start.py
Enter no. of training samples: 75
Enter no. of test samples: 75
Enter number of features: 4
Model Trained
Model Accuracy: 97.33%
Time: 0.0003380775451660156 seconds

(Incinerate-X) debasis@Debasis:~/project/temp$ python3 start2.py
Enter the training set (number of samples): 75
Enter the test set (number of samples): 75
Logistic Regression Accuracy: 94.67%
Elapsed time: 0.02 seconds
Random Forest Accuracy: 93.33%
Elapsed time: 0.09 seconds
Support Vector Machine Accuracy: 94.67%
Elapsed time: 0.00 seconds
K-Nearest Neighbors Accuracy: 93.33%
Elapsed time: 0.01 seconds

High-Dimensional Classification:
--------------------------------
Enter the training set (number of samples): 500
Enter the test set (number of samples): 500
Logistic Regression Accuracy: 59.20%
Elapsed time: 0.03 seconds
Random Forest Accuracy: 71.40%
Elapsed time: 0.29 seconds
Support Vector Machine Accuracy: 76.20%
Elapsed time: 0.02 seconds
K-Nearest Neighbors Accuracy: 65.00%
Elapsed time: 0.03 seconds

Enter no. of training samples: 500
Enter no. of test samples: 500
Enter number of features: 50
Model Trained
Model Accuracy: 66.60%
Time: 0.013143777847290039 seconds


Advantages:
-----------
Lowest Runtime and a Great Accuracy.

Applications:
-------------
Real-time applications where quick predictions are essential.
Large-scale datasets where computational efficiency is a priority.
Problems with relatively simple decision boundaries.