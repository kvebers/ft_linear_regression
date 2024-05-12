#!/usr/bin/env python3

import pandas as pd
import sklearn
from sklearn.linear_model import LinearRegression

df = pd.read_csv('data.csv')

print(df)