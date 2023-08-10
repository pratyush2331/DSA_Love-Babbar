import time
import numpy as np
from sklearn.linear_model import LinearRegression
from datetime import datetime

def must_parse_dt(dt_str):
    dt_format = "%Y-%m-%d %H:%M"
    dt_obj = datetime.strptime(dt_str, dt_format)
    return dt_obj.timestamp()

def abs_val(n):
    return (n ^ (n >> 63)) - (n >> 63)

def predict_missing_humidity(start_date, end_date, known_timestamps, humidity, timestamps):
    lm = LinearRegression()
    
    grid = np.empty((len(known_timestamps), 2))
    for i, (item, ts) in enumerate(zip(humidity, known_timestamps)):
        grid[i, 0] = item
        ts_diff = abs_val(int(time.time()) - int(must_parse_dt(ts)))
        grid[i, 1] = ts_diff

    lm.fit(grid[:, 1].reshape(-1, 1), grid[:, 0])
    
    grid_z = np.empty((len(timestamps), 2))
    for i, ts in enumerate(timestamps):
        ts_diff = abs_val(int(time.time()) - int(must_parse_dt(ts)))
        grid_z[i, 1] = ts_diff
    
    predicted = lm.predict(grid_z[:, 1].reshape(-1, 1))
    
    return predicted

if __name__ == "__main__":
    start_date = "2013-01-01"
    end_date = "2013-01-01"
    known_timestamps = [
        "2013-01-01 07:00",
        "2013-01-01 08:00",
        "2013-01-01 09:00",
        "2013-01-01 10:00",
        "2013-01-01 11:00",
        "2013-01-01 12:00",
    ]
    humidity = [10.0, 11.1, 13.2, 14.8, 15.6, 16.7]
    timestamps = [
        "2013-01-01 13:00",
        "2013-01-01 14:00",
    ]

    predictions = predict_missing_humidity(start_date, end_date, known_timestamps, humidity, timestamps)
    print(predictions)