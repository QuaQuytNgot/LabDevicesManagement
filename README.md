#Lab Devices Management
##File & function:
│
my_program/
├── main.cpp
include/
├── device_info.h                    
├── utils.h                   
├── my_borrow_return.h             
├── my_print.h           
src/
├── device_info.cpp                 
├── my_print.cpp              
├── my_borrow_return.cpp                   
├── utils.cpp                   
CMakeLists.txt              

##How to run?:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./my_program
