import time
import webbrowser

total_breaks = 3
break_count = 0

print("This program start on " + time.ctime())

while (break_count < total_breaks):
    time.sleep(10)
    webbrowser.open("https://music.163.com/#/song?id=556207187")
    break_count += 1
