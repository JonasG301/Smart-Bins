import serial
import time
import speech_recognition as sr
import openai
import subprocess
from dotenv import load_dotenv

openai.api_key='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' #Api key to get an answer form openAi
load_dotenv()
model= 'gpt-3.5-turbo'
s = serial.Serial('/dev/ttyACM0', 9600)  #Open serial port to comunicate with pi
s.isOpen()
time.sleep(0.5)

r = sr.Recognizer()
mic = sr.Microphone()
print("Start talking!")
with sr.Microphone() as source:
    print("Listing")
    
    while True:
        text = ""
        if (text == ""):
            audio = r.listen(source)
            try:
                text = r.recognize_google(audio, language = "de-DE")  #using of google speechrecognizion in language "de"
                time.sleep(1)
                print(f"You said: {text}")
                if not text:
                    continue
                text = "in welchen Mülleimer in Deutschladn kommt" + text + "bitte antworte in einem Wort, das entwerder Plastik, Bio oder Restabfalleimer ist." #prompfixing
                gptresponse = openai.ChatCompletion.create(model="gpt-3.5-turbo", messages=[{"role": "user",  "content":f"{text}"}])
                gptresponse_text = gptresponse.choices[0].message.content
                print(gptresponse_text)
                time.sleep(1)
                s.write(gptresponse_text.encode('utf-8')) #writes respons to the Arduino
            except sr.UnknownValueError:
                pass
            except KeyboardInterrupt:
                s.close()
                break
            