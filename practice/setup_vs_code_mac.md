## Setup Competitive

# Install Code Runner to run CPP files

[More Details about Code Runner Extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
Run Cntl + Alt + N 
Stop Cntl + Alt + M

# Add following command to handle specific Files

```
"code-runner.executorMap": {
      "javascript": "node",
      "php": "C:\\php\\php.exe",
      "python": "python",
      "perl": "perl",
      "ruby": "C:\\Ruby23-x64\\bin\\ruby.exe",
      "go": "go run",
      "html": "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\"",
      "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
      "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
      "cpp": "cd $dir && g++-12 $fileName -o app && cat input.txt | ./app > output.txt"
  }
```

Run individually cpp programs

g++-12 $fileName -o app && cat input.txt | ./app > output.txt

# Setup Code Editor

Create input.txt and output.txt

# Add create

# Option + Command + -> to split the tabs vertically
# Command + Option + 0 to split the tabs horizontally