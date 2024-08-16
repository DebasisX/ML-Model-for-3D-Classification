# Adaptive Ranged Based Hyperspace Classification Model 

1. Splitting of data and adaptation to dynamic ranges is performed while the process.
2. Data is Loaded
3. Testing Phase 

Time Complexity = O(n^2) Training 
                  O(n * m), where n is the number of test points and m is the number of model ranges.
Space Complexity = ls: 𝑂(𝑛), model: 𝑂(𝑚), where 𝑚 can approach 𝑂(𝑛) in the worst case.


Test Result: 
Upon training with 1000 datapoints for the current dataset we get 182 ranges.
Previous: 
---------
Training time: 
    real    0m5.866s
    user    0m4.658s
    sys     0m1.200s
Result: 
    Accuracy: 96.0% (Tested on 300)

Run using:
    python3 start.py
    python speedup.py
(Currently beats kNN in time, check udpated folder)
The newer model runs on 
Training: 𝑂 (𝑛 × 𝑚) in the average case and 𝑂(𝑛 × 𝑚^2) in the worst case, 
where m is the number of ranges in the model. Testing: 𝑂(𝑛 × 𝑚)