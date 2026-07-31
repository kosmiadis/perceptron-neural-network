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
