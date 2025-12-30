:again
rand > in.txt
sta <in.txt > sta_output.txt
test <in.txt > test_output.txt
fc sta_output.txt test_output.txt
if not errorlevel 1 goto again
pause