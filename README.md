testing tests


Requirements:

C/C++ testing (installed outside this repo):
gtest/gmock
rapidcheck

Python testing (installed with pip):
ctypes
unittest
hypothesis

To build:
1. ```mkdir -p build```
2. ```cd build && cmake ..```
3. ```make```

To run the c tests:
(in the build directory)
```ctest```

Additional info will be written in the "Temporary" directory

To run the python tests:
(in the build directory)
```../scripts/main.py```
# testrepo
