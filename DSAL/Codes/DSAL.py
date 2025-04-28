# Consider a telephone book database with N clients. Implement a hash table to quickly look up a client's telephone
# number, using two collision handling techniques and compare them based on the number of comparisons required
# to find a set of telephone numbers.
# (Telephone Book Database)
class TelephoneBook:
    def __init__(self, name, tel_no):
        self.name = name
        self.tel_no = tel_no

#**************************************************************************************

def Insertion_QuadProbing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    j = 1
    for _ in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashValue = t % 10  # hash function
        if hashtable[hashValue] is None:
            hashtable[hashValue] = TelephoneBook(n, t)  # creating obj and inserting
        else:
            while hashtable[hashValue] is not None:
                hashValue = (hashValue + (j * j)) % 10
                j += 1
            hashtable[hashValue] = TelephoneBook(n, t)
    return hashtable

#**************************************************************************************

def Insertion_DoubleHashing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    j = 2
    for _ in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashvalue = (t % 9) + (7 - (t % 7))  # using two hash functions
        if hashtable[hashvalue] is None:
            hashtable[hashvalue] = TelephoneBook(n, t)
        else:
            while hashtable[hashvalue] is not None:
                hashvalue = (t % 9) + j * (7 - (t % 7))
                hashvalue = hashvalue % 10  # ensure within range
                j += 1
            hashtable[hashvalue] = TelephoneBook(n, t)
    return hashtable

#**************************************************************************************

def Display_QP(hash1):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash1):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

#**************************************************************************************

def Display_DH(hash2):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash2):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

#**************************************************************************************

def Search(hash1, hash2):
    n = input("Enter name to search: ")
    f1 = 0
    f2 = 0
    for i, obj in enumerate(hash1):
        if obj is None:
            continue
        if obj.name == n:
            print("\nFound in Hashtable-1!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            f1 = 1
    for i, obj in enumerate(hash2):
        if obj is None:
            continue
        if obj.name == n:
            print("\nFound in Hashtable-2!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            f2 = 1
    if f1 == 0 and f2 == 0:
        print("\nNot found!!!\n")

#**************************************************************************************

def main():
    hash1 = [None for _ in range(10)]
    hash2 = [None for _ in range(10)]
    print("-------------------------------")
    print(" Group-A Assignment-1")
    while True:
        print("-------------------------")
        print("\t1. Insert Value")
        print("\t2. Display")
        print("\t3. Search")
        print("\t4. Exit")
        print("-------------------------")
        ch = int(input("Enter choice: "))
        if ch == 1:
            print("\nSelect collision method-")
            print("\t1. Quadratic Probing")
            print("\t2. Double Hashing")
            c = int(input("Enter choice: "))
            if c == 1:
                hash1 = Insertion_QuadProbing()
            elif c == 2:
                hash2 = Insertion_DoubleHashing()
            else:
                print("! Enter valid collision choice.")
        elif ch == 2:
            print("\t1. Display QP")
            print("\t2. Display DH")
            c1 = int(input("Enter choice: "))
            if c1 == 1:
                Display_QP(hash1)  # Display Quadratic Probing hash table
            elif c1 == 2:
                Display_DH(hash2)  # Display Double Hashing hash table
            else:
                print("! Enter valid display choice.")
        elif ch == 3:
            Search(hash1, hash2)
        elif ch == 4:
            quit()
        else:
            print("! Enter valid choice.")

# Start the program
main()
