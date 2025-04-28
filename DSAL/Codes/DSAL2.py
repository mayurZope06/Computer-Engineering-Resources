# Implement a dictionary using hashing, handling collisions with chaining (with and without replacement). The
# dictionary should have standard operations like Insert, Find, and Delete, where keys are unique and comparable.
# (Hash Table Implementation)
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [None] * self.size

    def _hash(self, key):
        # Simple hash function using built-in Python hash and modulo
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        new_node = Node(key, value)

        if self.table[index] is None:
            self.table[index] = new_node
        else:
            current = self.table[index]
            while current:
                if current.key == key:
                    # If key already exists, update value (with replacement)
                    current.value = value
                    return
                if current.next is None:
                    break
                current = current.next
            # Append at the end if key was not found
            current.next = new_node

    def find(self, key):
        index = self._hash(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None  # Key not found

    def delete(self, key):
        index = self._hash(key)
        current = self.table[index]
        prev = None
        while current:
            if current.key == key:
                if prev is None:
                    # Deleting the first node
                    self.table[index] = current.next
                else:
                    prev.next = current.next
                return True
            prev = current
            current = current.next
        return False  # Key not found

    def display(self):
        for i in range(self.size):
            print(f"Index {i}: ", end="")
            current = self.table[i]
            if current is None:
                print("Empty")
            else:
                while current:
                    print(f"({current.key}: {current.value})", end=" -> ")
                    current = current.next
                print()

# Main program to interact with the user
def main():
    hash_table = HashTable()
    while True:
        print("\nDictionary Operations:")
        print("1. Insert (key, value)")
        print("2. Find (key)")
        print("3. Delete (key)")
        print("4. Display")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = input("Enter key: ")
            value = input("Enter value: ")
            hash_table.insert(key, value)
            print("Inserted successfully.")

        elif choice == 2:
            key = input("Enter key to find: ")
            result = hash_table.find(key)
            if result is None:
                print("Key not found.")
            else:
                print(f"Value for key {key}: {result}")

        elif choice == 3:
            key = input("Enter key to delete: ")
            if hash_table.delete(key):
                print(f"Key {key} deleted successfully.")
            else:
                print(f"Key {key} not found.")

        elif choice == 4:
            hash_table.display()

        elif choice == 5:
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
