import sys
import speech_recognition as sr

def transcribe_audio(audio_file):
    recognizer = sr.Recognizer()
    with sr.AudioFile(audio_file) as source:
        audio_data = recognizer.record(source)
    try:
        transcript = recognizer.recognize_google(audio_data)
        return transcript
    except sr.UnknownValueError:
        return "Speech recognition could not understand audio"
    except sr.RequestError as e:
        return f"Could not request results from Google Speech Recognition service; {e}"

# Example usage
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python speech_recognition.py <audio_file>")
        sys.exit(1)
    audio_file = sys.argv[1]
    transcript = transcribe_audio(audio_file)
    print(transcript)