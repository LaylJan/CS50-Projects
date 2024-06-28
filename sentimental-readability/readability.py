from cs50 import get_string

TEXT = get_string("Text: ")

wordCount = 0
letterCount = 0
sentenceCount = 0

text = TEXT

text = text.upper()

for i in range(len(text)):
    if text[i] == " ":
        wordCount += 1
    elif text[i] in ["?", "!", "."]:
        sentenceCount += 1
    x = ord(text[i]) - ord("A")
    if 0 <= x <= 25:
        letterCount += 1
wordCount += 1

L = letterCount / wordCount * 100
S = sentenceCount / wordCount * 100

x = round(0.0588 * L - 0.296 * S - 15.8)

if x < 1:
    print("Before Grade 1")
elif x > 16:
    print("Grade 16+")
else:
    print("Grade", x)
