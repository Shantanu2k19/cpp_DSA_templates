import os

def delete_unwanted_file(start_dir):
    for dirPath, dirNames, fileNames in os.walk(start_dir):
        for filename in fileNames:
            # if not os.path.splitext(filename)[1] or filename.endswith('.o'):
            if filename.endswith('.o'):
                file_path = os.path.join(dirPath, filename)
                try:
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e: 
                    print(f"Error deleting {file_path}: {e}")

if __name__ == "__main__":
    start_directory = os.getcwd()
    delete_unwanted_file(start_directory)
