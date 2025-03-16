
# C Redis

C Redis is a simplified, Redis-inspired in-memory key-value store written in C for educational purposes.

## Features
- In-memory key-value store using a hash table
- Command parser with `SET`, `GET`, `DEL`
- ASCII art banner on startup
- Modular structure: headers, src, and build directories


## Build & Run
```sh
make              # Build the project (executable in build/c-redis)
./build/c-redis   # Run the database

## Commands
- SET key value — Store a key-value pair.
- GET key — Retrieve a value.
- DEL key — Delete a key.
- EXIT — Exit the program.


Contributions are welcomed!
