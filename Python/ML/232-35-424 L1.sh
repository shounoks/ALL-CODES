#!/bin/bash

while true; do
  clear
  echo "SYSTEM MONITORING DASHBOARD"
  echo "1. Show Memory Usage"
  echo "2. Show CPU Usage"
  echo "3. Show Disk Usage"
  echo "4. Show Network Info"
  echo "5. Top 5 CPU-consuming Processes"
  echo "6. Show Logged-in Users"
  echo "7. Exit"
  echo "          -----X-----         "
 
  read -p "Select an option [1-7]: " choice

  case $choice in
    1)
      echo " Memory Usage "
      free -h
      ;;
    2)
      echo " CPU Usage "
      mpstat -P ALL 1 1   
      ;;
    3)
      echo " Disk Usage "
      df -h
      ;;
    4)
      echo " Network Info "
      ip -4 a | grep inet
      echo "Network Data Sent or Network Data Received"
      cat /proc/net/dev
      ;;
    5)
      echo " Top 5 Processes (by CPU) "
      ps aux --sort=-%cpu | head -n 6
      ;;
    6)
      echo " Logged-in Users "
      who
      ;;
    7)
      echo "Exiting Dashboard.................."
      exit
      ;;
    *)
      echo "Invalid option. Please choose again(1–7)."
      ;;
  esac

  read -p "Press Enter to return to main menu..."
done

