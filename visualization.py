# -*- coding: utf-8 -*-
"""
Created by Sankalok Sen

Execute on Google Colaboratory ^_^
"""

#Mounting Google Drive
from google.colab import drive
drive.mount('/content/drive')

import pandas as pd
import plotly.express as px
import plotly.graph_objects as go

fileInterest = pd.read_csv('/content/drive/MyDrive/amortization-schedule/interest.txt')
filePrincipal = pd.read_csv('/content/drive/MyDrive/amortization-schedule/principal.txt')

fileInterest.to_csv('/content/drive/MyDrive/amortization-schedule/interest.csv', index = None)
filePrincipal.to_csv('/content/drive/MyDrive/amortization-schedule/principal.csv', index = None)

fig = go.Figure()

fig.add_trace(go.Scatter(y = fileInterest['Interest'], mode = 'lines', name = 'Interest paid every Installment'))
fig.add_trace(go.Scatter(y = filePrincipal['Principal Paid'], mode = 'lines', name = 'Principal paid off every Installment'))
fig.show()
