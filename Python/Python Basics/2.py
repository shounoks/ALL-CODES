import time
import sys
import webbrowser


def typewriter_effect(text, delay=0.06):
    """
    Prints text character by character.
    """
    for char in text:
        sys.stdout.write(char)
        sys.stdout.flush()
        time.sleep(delay)
    print()


def play_let_me_love_you():
    # Justin Bieber - Let Me Love You (Lyric Video)
    youtube_url = "https://youtu.be/SMs0GnYze34"

    # Lyrics Data: (Line, Pause Duration after printing)
    # This covers the First Verse, Pre-Chorus, and Chorus
    lyrics = [
        # Verse 1
        ("I used to believe", 1.8),
        ("We were burnin' on the edge of somethin' beautiful", 3.0),
        ("Somethin' beautiful...", 1.5),
        ("Selling a dream", 2.0),
        ("Smoke and mirrors keep us waitin' on a miracle", 3.0),
        ("On a miracle...", 2.5),

        # Pre-Chorus
        ("Say, go through the darkest of days", 2.2),
        ("Heaven's a heartbreak away", 2.0),
        ("Never let you go, never let me down", 3.0),
        ("Oh, it's been a hell of a ride", 2.2),
        ("Driving the edge of a knife", 2.0),
        ("Never let you go, never let me down", 2.5),

        # Chorus
        ("Don't you give up, nah-nah-nah", 2.2),
        ("I won't give up, nah-nah-nah", 2.2),
        ("Let me love you...", 2.5),
        ("Let me love you...", 3.0),
        ("Don't you give up, nah-nah-nah", 2.2),
        ("I won't give up, nah-nah-nah", 2.2),
        ("Let me love you...", 2.5),
        ("Let me love you...", 2.5),
        ("Oh, baby, baby...", 3.0)
    ]

    print("\n>> Step 1: Opening YouTube Link...")
    webbrowser.open(youtube_url)

    print("\n" + "=" * 60)
    print(">> INSTRUCTION: Wait for the video to load.")
    print(">> PRESS 'ENTER' exactly when he sings: 'I used to believe'")
    print("=" * 60 + "\n")

    # The code pauses here until YOU press Enter
    input("Press Enter to start lyrics sync...")

    print("\n🎵 LET ME LOVE YOU 🎵\n")

    # Small buffer to match typing speed with singing
    time.sleep(0.2)

    for line, duration in lyrics:
        typewriter_effect(line)
        time.sleep(duration)


if __name__ == "__main__":
    play_let_me_love_you()