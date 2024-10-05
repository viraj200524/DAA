import csv
from collections import defaultdict

# Function to count inversions in an array
def count_inversions(arr):
    count = 0
    n = len(arr)
    
    # Using a simple nested loop to count inversions
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                count += 1
    return count

# Read data from CSV file and handle negative test cases

l = ['students_courses_pos_1.csv','students_courses_pos_2.csv','students_courses_neg_1.csv','students_courses_neg_2.csv', 'positive_case_1.csv', 'positive_case_2.csv', 'positive_case_3.csv', 'negative_case_1.csv', 'negative_case_2.csv', 'negative_case_3.csv']
for path in l:
    file_path = path  # Change the file path to the appropriate file
    students_courses = []

    with open(file_path, mode='r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            # Handle Student_ID validation
            try:
                student_id = int(row['Student_ID'])
            except (ValueError, TypeError):
                print(f"Invalid Student_ID: {row['Student_ID']} - Skipping this entry.")
                continue

            # Handle Courses validation
            try:
                courses = list(map(int, row['Courses'].split(', ')))
                # Ensure all course numbers are in the valid range (e.g., 1-7)
                if any(course < 1 or course > 7 for course in courses):
                    print(f"Invalid course values: {row['Courses']} - Skipping this entry.")
                    continue
            except ValueError:
                print(f"Invalid course list: {row['Courses']} - Skipping this entry.")
                continue

            students_courses.append((student_id, courses))

    # Calculate count inversions for each student and store them in a list
    inversion_counts = []
    for student_id, courses in students_courses:
        inversion_count = count_inversions(courses)
        inversion_counts.append(inversion_count)

    # Group students by their inversion counts
    inversion_groups = defaultdict(list)
    for i, count in enumerate(inversion_counts):
        inversion_groups[count].append(students_courses[i][0])  # Store valid Student_ID

    # Return the grouped results
    grouped_students = dict(inversion_groups)

    # Print the grouped students by inversion count in ascending order
    for count, student_ids in sorted(grouped_students.items()):
        print(f"Inversion Count {count}: Student IDs: {student_ids}")
    print('\n\n')