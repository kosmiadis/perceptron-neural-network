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

In a case where the input vector is X=(x1, x2,..., xn), we check if the dot product of the two vectors W⋅X is bigger than a hyperparameter θ (theta) 

If it is bigger than the specified θ then the neuron gets activated and it pulses signals, if not the neuron stays inactive.

The mathematical representation of the above concept is the following:

**Let u = W^T ⋅ X - θ, and let y = f(u)= { 0, if u <=0 and 1 if u > 0 }**
