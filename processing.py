import pandas as pd
from datetime import time

class Task:
    def __init__(self, description: str, duration: time, priority: int, after: time, before: time):
        self.description = description
        self.duration = duration
        self.priority = priority
        self.after = after                               # 12:01 a.m. if not available
        self.before = before                             # 11:59 p.m. if not available
    
    def __str__(self):
        return f"Event: {self.description}, Duration: {self.duration}, Priority: {self.priority}, 
                 After: {self.after}, Before: {self.before}"

class Schedule:
    def __init__(self, description: str, start: time, end: time):
        self.description = description
        self.start = start
        self.end = end
    def __str__(self):
        return f"Event: {self.description}, Start: {self.start}, End: {self.end}"
    
def time_to_minutes(timey: time) -> int:
    return timey.hour * 60 + timey.minute

def read_schedule():
    pd.read_csv("schedule.csv", sep=)


def main() -> int:

    return 0;