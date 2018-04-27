echo clean all Windows compiled binaries

del /s /q Solution\Windows\x64\Debug\*
del /s /q Solution\Windows\x64\Release\*

del /s /q Solution\Windows\LightFileSync\x64\Debug\*
del /s /q Solution\Windows\LightFileSync\x64\Release\*

rmdir /s /q Solution\Windows\.vs\

@echo pause