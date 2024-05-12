#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('data.csv')
prediction_data = pd.read_csv('training_data.csv')
plt.plot(data['km'], data['price'], 'o', color='red')
theta0 = prediction_data['theta0'].values[0]
theta1 = prediction_data['theta1'].values[0]
labels = [int(min(data['km'])), int(max(data['km']))]
predicted_values = [theta0 + theta1 * x for x in labels]
print(predicted_values)
plt.plot(labels, predicted_values, color='blue')
plt.xlabel('Kilometers')
plt.ylabel('Price')
plt.title('Price prediction based on kilometers')
plt.show()