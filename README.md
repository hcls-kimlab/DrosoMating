# Fruit Flies Mating Analysis Tool

This tool analyzes fruit flies mating behavior from video recordings and generates a CSV file with metrics.

## Download
You can download the latest executable file from the releases section. Opencv is needed.
[ff-choose.exe](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/releases/ff-choose.exe)

## Usage

### Step 0: Open the Application
Run `ff-choose.exe` to start the program.  
![Step 0](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/1.png)

### Step 1: Select MP4 File
Choose the video file to analyze.  
![Step 1](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/2.png)

### Step 2: Input Board Numbers and Velocity
Enter the number of boards and velocity parameter.  
![Step 2](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/3.png)

### Step 3: Click Corners
Define the region of interest by clicking the corners.  
![Step 3](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/4.png)

### Step 4: Click Flies and Set Threshold
1. Click on the flies **3 times**.
2. Set the detection threshold.
3. Press `Enter` to confirm.  
![Step 4a](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/5.png)  
![Step 4b](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/6.png)

### Step 5: Wait for Processing
Output file will be in the video folder:  
`[Video Name]_output_[board numbers].csv`

---

## Results

### Output CSV File
File name: `[Video Name]_output_[board numbers].csv`  
![Output Preview](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/7.png)

### Metrics
- **courtship_duration(min)**: Total chasing time
- **mate_duration(min)**: Mating duration
- **CI**: Courtship Index for first 10 minutes
- **court_start_time(min)**: Time to first chasing
- **mate_start_time(min)**: Mating start time
- **mate_end_time(min)**: Mating end time

### Example Table
![Table Example 1](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/8.png)  
![Table Example 2](https://github.com/hcls-kimlab/DrosoMating/blob/win-ff/docs/png/9.png)
