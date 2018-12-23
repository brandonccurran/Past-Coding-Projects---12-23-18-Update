You’re going to write an encoder that given an integer value representing a character’s Unicode code point value, outputs a “bytes” object representing that character as UTF-8. You’re then going to write a decoder that given a bytes object representing a UTF-8 encoded Unicode value, returns the numeric value of the corresponding codepoint.

You should not worry about carefully filtering valid/invalid characters, like the “invalid encodings” described in the Wikipedia article for UTF-8: Just (naively) encode/decode the codepoints/bytes that are passed to your functions.

Python already has the tools to do this task, though I want you to do it manually using bitwise operations.You’re going to write an encoder that given an integer value representing a character’s Unicode code point value, outputs a “bytes” object representing that character as UTF-8. You’re then going to write a decoder that given a bytes object representing a UTF-8 encoded Unicode value, returns the numeric value of the corresponding codepoint.

You should not worry about carefully filtering valid/invalid characters, like the “invalid encodings” described in the Wikipedia article for UTF-8: Just (naively) encode/decode the codepoints/bytes that are passed to your functions.

Python already has the tools to do this task, though I want you to do it manually using bitwise operations.




**** STARTER CODE ****

def encode(codepoint):
    if codepoint < 128:
        return bytes([codepoint])


def decode(bytes_object):
    if len(bytes_object) == 1:
        return bytes_object[0]







All credit for starter code and project documentation belongs to Marc Liberatore
https://people.cs.umass.edu/~liberato/home/