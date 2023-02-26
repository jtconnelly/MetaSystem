Why do we need it:
    In projects where your types may have to end up being ambiguous (ie. creating a Variant or "Any" type), you will always have to go back to fundamental types. 
    If you can simplify everything down to it's fundamental types, then even your most complex objects can be broken down and carried around. 
    We can also use this whenever we want to incorporate scripted languages to create my types (ie. Lua to create C++ types)
    Both of these uses have been tested in other meta systems and other projects, but cannot be ripped out of their original uses
    This can also be used for other parsers such as JSON, XML, etc.

What are some things objects that are meta-fied might have:
    Properties (Classes have variables, we need to pull those out)
    Methods (Class/Object methods in case we want to call them.)
    Pretty (How that object will be printed)
    

What we may or may not need?:
    Parser (Convert from string to type)

Other Notes:
