print("Simple Chatbot")
print("Type 'bye' to exit")

while True:
    msg = input("You: ").lower()

    if msg == "hello":
        print("Bot: Hello! How can I help you?")
    elif msg == "how are you":
        print("Bot: I am fine.")
    elif msg == "what is your name":
        print("Bot: I am a simple chatbot.")
    elif msg == "help":
        print("Bot: You can say hello, how are you, name, bye")
    elif msg == "thanks":
        print("Bot: You are welcome.")
    elif msg == "bye":
        print("Bot: Goodbye!")
        break
    else:
        print("Bot: Sorry, I did not understand.")

# hello
# how are you
# help
# thanks
# bye

# Hello! How can I help you?
# I am fine.
# You can say hello...
# You are welcome.
# Goodbye!

# print("Simple Chatbot (type 'bye' to exit)")

# while True:
#     user_input = input("You: ").lower()

#     if user_input == "hello":
#         print("Bot: Hi! How can I help you?")
#     elif user_input == "how are you":
#         print("Bot: I'm doing great!")
#     elif user_input == "bye":
#         print("Bot: Goodbye!")
#         break
#     else:
#         print("Bot: Sorry, I didn't understand that.")


# 10) Elementary Chatbot

# Explanation:
# A chatbot is a simple interactive program that gives predefined responses to user input. It usually works using rules and conditions.

# Time Complexity: O(1) per input in a simple rule-based bot
# Space Complexity: O(1)

# Viva Q&A:
# Q1. What is a chatbot?
# A program that interacts with users through messages.

# Q2. Is this chatbot AI-based?
# Not necessarily; a simple chatbot is rule-based.

# Q3. Where are chatbots used?
# Customer support, booking systems, and assistants.

# Q4. Why is it called elementary?
# Because it uses basic matching rules only.
