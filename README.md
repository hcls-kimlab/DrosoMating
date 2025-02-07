# Fruit Flies Mating Analysis Tool

This tool analyzes fruit flies mating behavior from video recordings and generates a CSV file with metrics.

## Usage

### Step 0: Open the Application
Run `ff-choose.exe` to start the program.  
Screenshot: https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/1.png

### Step 1: Select MP4 File
Choose the video file to analyze.  
Screenshot: https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/2.png

### Step 2: Input Board Numbers and Velocity
Enter the number of boards and velocity parameter.  
Screenshot: https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/3.png

### Step 3: Click Corners
Define the region of interest by clicking the corners.  
Screenshot: https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/4.png

### Step 4: Click Flies and Set Threshold
1. Click on the flies **3 times**.
2. Set the detection threshold.
3. Press `Enter` to confirm.  
Screenshots:  
https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/5.png  
https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/6.png

### Step 5: Wait for Processing
Output file will be in the video folder:  
`[Video Name]_output_[board numbers].csv`

---

## Results

### Output CSV File
File name: `[Video Name]_output_[board numbers].csv`  
Preview: https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/7.png

### Metrics
- **courtship_duration(min)**: Total chasing time
- **mate_duration(min)**: Mating duration
- **CI**: Courtship Index for first 10 minutes
- **court_start_time(min)**: Time to first chasing
- **mate_start_time(min)**: Mating start time
- **mate_end_time(min)**: Mating end time

### Example Table
Preview screenshots:  
https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/8.png  
https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/png/9.png
