import random

pickup_lines = [
    "Are you a magician? Because whenever I look at you, everyone else disappears.",
    "Do you have a map? I just got lost in your eyes.",
    "Are you an interior decorator? When I saw you, the entire room became beautiful.",
    "Is your name Google? Because you have everything I've been searching for.",
    "Do you have a sunburn, or are you always this hot?",
    "If you were a vegetable, you'd be a cute-cumber!",
    "Do you have a name, or can I call you mine?",
    "Is your dad a baker? Because you're a cutie pie!",
    "Are you a camera? Every time I look at you, I smile.",
    "Is your name Wi-Fi? Because I'm really feeling a connection.",
    "Do you have a Band-Aid? I just scraped my knee falling for you.",
    "Are you made of copper and tellurium? Because you're Cu-Te!",
    "Is your name Bluetooth? Because I'm really feeling a connection.",
    "Is your name Ariel? Because we mermaid for each other.",
    "Are you an app? Because I can't seem to close you out of my mind.",
    "If you were a cat, you'd purr-fectly fit in my lap.",
    "Can I follow you home? Because my parents always told me to follow my dreams.",
    "Is your name Cinderella? Because I see that dress disappearing by midnight.",
    "are you a diary ? Because I wanna tell everything to you",
]

def generate_pickup_line():
    return random.choice(pickup_lines)

if __name__ == "__main__":
    print("Here's a pickup line for you:")
    print(generate_pickup_line())
