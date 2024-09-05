from flask import Flask, request, render_template
import pandas as pd
import os

configuring = Flask(__name__)

# Define the path for the CSV file
csv_file_path = 'submissions.csv'

@configuring.route('/')
def form():
    return render_template('schedule.html')

@configuring.route('/submit', methods=['POST'])
def submit():
    # Get the form data
    desc = request.form.getlist('desc')
    start = request.form.getlist('start')
    end = request.form.getlist('end')

    # Create a DataFrame from the form data
    df = pd.DataFrame({
        'Description': desc,
        'Start Time': start,
        'End Time': end
    })

    # Check if the CSV file already exists
    if not os.path.isfile(csv_file_path):
        # If the file does not exist, write the DataFrame as a new CSV
        df.to_csv(csv_file_path, index=False)
    else:
        # If the file exists, append without writing the header
        df.to_csv(csv_file_path, mode='a', header=False, index=False)

    return 'Form submitted successfully!'

if __name__ == '__main__':
    configuring.run(debug=True)
