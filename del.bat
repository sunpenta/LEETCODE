for /f "delims=" %%i in ('dir /b /a-d /s "*.exe"') do del "%%i"
Pause