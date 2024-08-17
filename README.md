# ML-model in Python and C 
Adaptive Hierarchical Classification Model with Dynamic Ranging.


This is going to be quite an intensive project, as I am working solo.
This project is divided into two parts one in C for single featured classification.
Another is using Python3 for Hyperspace(x, y, z) IO pairs, which is in the hyperspace directory. 

This currently supports training and testing on both single and 3D inputs, it is a multiple output classifier model.

# Update:
---------
- Added support for higher dimensions. I've developed the idea for 3D classification 
but it can be scaled to further higher dimensions just by adding in more feature inputs and using similar logic.
- Added the PDF of the idea.
- Further implementation will be done in Python or it will get more complex and will be more prone to errors.
- Currently writing the code for the idea. Will be up in some time.
  
Example usage:

Get yourself a dataset.csv with io pairs.
and place it in dataset/dataset.csv.

Go into the model dir,
run ./model.exe (for single featured)
run python3 start.py (for 3D io pairs.)

Test on different inputs.
Both have great accuracy as they adapt when trained.

I have added a plot of the model after training to compare against the dataset and we can see it does a pretty good job.
The model's accuracy depends on the no. of training samples. Not everytime more samples are better. So you can use an 
iterative approach to train the model at what point it is best. 
If you don't know how to do so look into my updated folder n.py and follow a similar approach.

Thank You.
