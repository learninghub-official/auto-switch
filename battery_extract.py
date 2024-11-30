import psutil
import firebase_admin
from firebase_admin import credentials, db
import time

# Initialize Firebase Admin SDK
cred = credentials.Certificate("autoswitch-b5b8c-firebase-adminsdk-ixnkr-083658fe96.json")    #path to Jsonfile downloaded from Project
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://autoswitch-b5b8c-default-rtdb.firebaseio.com/'  #Realtime data base URL
})

def get_battery_status():
    battery = psutil.sensors_battery()
    return battery.percent, battery.power_plugged

def send_to_firebase(battery_level, is_plugged):
    data = {
        'battery_level': battery_level,
        'is_plugged': is_plugged
    }
    ref = db.reference('laptop_battery')
    ref.set(data)

while True:
    battery_level, is_plugged = get_battery_status()
    send_to_firebase(battery_level, is_plugged)
    print(f"Battery: {battery_level}%, Plugged In: {is_plugged}")
    time.sleep(30)  # Update every 30 seconds