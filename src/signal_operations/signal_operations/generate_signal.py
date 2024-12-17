import numpy as np
import random
import matplotlib.pyplot as plt
from scipy.interpolate import splrep, splev

def generate_control_points(n_points=20, length=1000, value_range=(-1, 1)):
    # Losowe punkty kontrolne
    np.random.seed(random.randint(1,1000))
    x = np.linspace(0, 1, n_points)
    y = np.random.uniform(value_range[0], value_range[1], n_points)
    
    # Interpolacja splinem
    tck = splrep(x, y, s=1)
    x_new = np.linspace(0, 1, length)
    y_new = splev(x_new, tck)

    return y_new
