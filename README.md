# Sample O3DE project to test Pointclouds

## Setup

Use current stabilization/2409 branch of o3de engine

Assumptions:
 - `C:\o3de\o3de` points to o3de source/installation
 - `E:\O3DE_Project\sample_o3de_project` points to cloned location of this repository.
Setup submodules:

```ps
cd E:\O3DE_Project\sample_o3de_project
git submodule init
git submodule update
```

Register gem in question:
```ps
 C:\o3de\o3de\scripts\o3de.bat register -gp E:\O3DE_Project\sample_o3de_project\extra_gems\robotec-o3de-tools\Gems\Pointcloud\
```

Configure project for visual studio:
```ps
cd E:\O3DE_Project\sample_o3de_project\project
cmake -B build/windows -S . -G "Visual Studio 16"
```
And build
```
cmake --build build/windows --target Editor --config profile -- -m
```
