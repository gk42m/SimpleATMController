# How to build

## 1. Windows 11

I developed Windows environment. I checked the operation(Build/Run Tests) only in Windows environment.

## 2. Install Git for Windows

[Git for Windows 2.x](https://git-scm.com/download/win)  

actually my git version is  
> git version 2.30.2.windows.1

## 3. Install Visual Studio 2022

You can download community Edition.
[Visual Studio 2022](https://visualstudio.microsoft.com/downloads/)

When installing Visual Studio, you need the “Desktop development with C++” workload installed for building windows,  
including all of its default components.

***Note: Visual Studio is different than Visual Studio Code.***

## 4. Install vcpkg

I manage dependency library using vcpkg.

> git clone <https://github.com/Microsoft/vcpkg.git>  
> cd vcpkg  
> ./bootstrap-vcpkg.sh  
> ./vcpkg integrate install  

## 5. Clone project

> git clone <https://github.com/gk42m/SimpleATMController.git>  

## 6. Build project

The main() function is in main.cpp file.

> 1. open SimpleATMController.sln file  
> 2. check solution configurations is Debug or Release  
> 3. menu -> Debug -> start without Debugging(Ctrl + F5)

## 7. Run Tests

Test cases are written in test.cpp file.  
I use Catch2 Framework and Written in BDD style Tests.

> 1. open SimpleATMController.sln file  
> 2. check solution configurations is RunTest  
> 3. menu -> Debug -> start without Debugging(Ctrl + F5)

## *. Class Diagram

![uml](http://www.plantuml.com/plantuml/proxy?src=https://github.com/gk42m/SimpleATMController/blob/master/uml.puml)
