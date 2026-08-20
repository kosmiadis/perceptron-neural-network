## Perceptron Neural Network Implementation

This repository is an implemenation of the Perceptron Neural Network.
It uses the McCulloch-Pitts Model, as referenced from the book "Μηχανική Μάθηση, Κωνσταντίνος Διαμαντάρας, Δημήτρης Μπότσης"

### The McCulloch-Pitts Model

This model was created in 1940, by McCulloch and Pitts. They created a model that simulated the neuron activity pattern of our neurons.

A neuron could be in one of the following states: 
- y=0 The neuron is inactive, it does not pulse signals
- y=1 The neuron is active, it does pulse signals in high frequencies

Neural synapses are described by the synaptic weights W(i)(i=1....)

The synaptic weights ( W=(w1, w2,..., wn) ) could be:
- Positive real numbers if y=1 (neuron is active)
- Negative real numbers if y=0 (neuron is inactive) 

In a case where the input vector is X=(x1, x2,..., xn), we check if the dot product of the two vectors W⋅X is bigger than a threshold θ (theta) 

If it is bigger than the specified θ then the neuron gets activated and it pulses signals, if not the neuron stays inactive.

The mathematical representation of the above concept is the following:

**Let u = W^T ⋅ X - θ, and let y = f(u)= { 0, if u <=0 and 1 if u > 0 }**
The variable ***u*** is called **weighted sum** and the function ***f*** is called a **step function**

Because θ as a threshold is just a positive or a negative real number we can write it in the following sense: w0⋅x0 where w0=-θ (bias)  and x0=1 so at the end we have the formula

u = W^T ⋅ X, W and X belong to R^N+1 (+1 because we added the threshold as a factor of the dot product)

The parameters that influence the y value is the **synaptic weights** and the **bias w0**

The equation u = W⋅X + b = 0 corresponds to a hyperplane at the n-dimension space R^n

The vectors X such that u(X) > 0 and those whose u(X) < 0 are being separated by the hyperplane. The ones that u(X) = 0 belong to the hyperplane. 

In conclusion the hyperplane u = 0, separates the space into two groups, the first is the one tagged as y=1 and the second tagged as y=0. 

We can get a better understanding of this if we examine a hyperplane to the 2-dimensional space, R^2.

Let u = w1*x1 + w2*x2 + b = 0, is a line that is vertical to the synaptic weigth vector w=(w1, w2)

The area that follows the w's direction is the area where it applies u(x) > 0, thus y=1
The are that follows the w's opposite direction is the are where it applies u(x) < 0, thus y=0

The distance between the line and the xy-axis origin, is dependant of the bias **b**

- If b=0 then the line crosses the xy-axis origin
- If b>0 then the line's displacement follows the opposite direction of the **w** vector
- If b<0 then the line's displacement follows the same direction of the **w** vector

### Training of Perceptron Neural Network

The dataset of this project can be found here [View Dataset](https://www.kaggle.com/datasets/mexwell/body-measurements)

## Training
The model is being trained with the data found in the ***data.csv*** file, by calling the function ***train_from_csv("data.csv")***

The function performs the following:

1. Reads the csv format data from the data.csv file
2. Creates a ***training_dataset*** vector that contains pairs with the first element being a vector of features and the second element the class target formatting the csv data to suitable formatted data
3. Calls the model's ***train*** method which feeds the data to the model in order to calculate the appropriate weights and bias

## Training Algorithm

Before we start describing the algorithm the terms **Epoch** must be defined.

With a simple search in Google we can find the following:
[***Epoch***](https://www.google.com/search?q=epoch+machine+learning&sca_esv=cf5c3a640caff83a&rlz=1C5CHFA_enGR1189GR1189&sxsrf=APpeQntBD0xUNQPohNbXryvA_WbpXs9WCw%3A1787134818245&ei=YoOFarLCDseRxc8PndftkAE&biw=1470&bih=801&ved=0ahUKEwiy-4aAvKyWAxXHSPEDHZ1rGxIQ4dUDCBA&uact=5&oq=epoch+machine+learning&gs_lp=Egxnd3Mtd2l6LXNlcnAiFmVwb2NoIG1hY2hpbmUgbGVhcm5pbmcyBRAAGIAEMggQABgWGB4YCjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB5I3hJQzQNYrBJwAXgBkAEAmAGIAaABrgyqAQM3Lji4AQPIAQD4AQGYAhCgAsUMwgIKEAAYRxjWBBiwA8ICDRAAGIAEGIoFGEMYsAPCAg4QABjkAhjWBBiwA9gBAcICFxAuGNwGGLgGGNoGGNgCGMgDGLAD2AEBwgIEECMYJ8ICChAAGIAEGIoFGEPCAhEQLhivARjHARiABBiYBRiZBZgDAIgGAZAGD7oGBggBEAEYCZIHBDUuMTGgB8xcsgcENC4xMbgHwwzCBwQxMi40yAcQgAgB&sclient=gws-wiz-serp): In machine learning, an epoch represents one complete pass of the entire training dataset through a machine learning model

The training starts by initializing the weights and the bias with random values that belong to the set [ -0.5 , 0.5 ], in general we initialize the weights with small positive real values. 

We set the learning step ***a*** as a small positive real value, in this case the value is set to **0.1**

The model's training will stop when either one of these sentences is true:
1. The errors the model makes with the newly updated weights are 0 for the specific epoch, where the epoch < 2000
2. The epochs_threshold=2000 criteria is met. 

**Note**
The epochs_threshold is being set to 2000 after trial and errors as a good value for the model to learn quite good from the data provided. 

1. In the first case the model does not make any mistake and thus it's accuracy is 100%, furthermore meaning that the data is linearly separable. 

2. In the second case the model stops the training procedure as any further training will not improve the model's performance, meaning that some data that belong to different classes are relatively close or on top of the border of the hyperplane, thus some vectors are misclassified. You can find out the errors made each time of the model's training by just printing the model itself. The model has an overloaded **>>** operator so it would print specific analytics about the model.

The training is relatively simple. Each vector passes through the **weighted sum**, and then the weighted sum acts as an input value to the **step function**.
If the output of the step function is the same as the class target that was provided by the second element of the pair, in which the vector was the first, then there is no error, if the classification is different then there is an error and the weights and bias are recalculated. 

This process continues until one of the two previously mentioned criteria is met.

The ***predict*** function works by passing the to be classified input vector through the adjusted weighted sum and the ouput through the step function. The classification is the return value, either 0 or 1.



