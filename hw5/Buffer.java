public class Buffer {
    private int head;
    private int tail;
    private int[] arr;
    private int size;
    private int buffsize = 0;

    public Buffer(int size) {                   //Buffer constructor. Creates new array and initilizes head and tail pointers.
        arr = new int[size];
        int tail = 0;
        int head = 0;
        this.size = size;
    }
    
    public void push(int s) {                   // Insert method. Adds element passsed as argument to array and increments the appropriate pointers.
        arr[head] = s;
        head = (head + 1) % size;
        buffsize++;
        return;
    }

    public int pop() {                          // Remove method. Returns the element refered to by the tail pointer and increments the appropriate pointer.
        int r = arr[tail];
        tail = (tail + 1) % size;
        buffsize--;
        return r;
    }

    public boolean isEmpty() {                  // Returns true if buffer is empty, false otherwise.
        if (buffsize == 0) {
            return true;
        }
        return false;
    }

    public boolean isFull() {                   // Returns true if the buffer is full, false otherwise.
        if(buffsize == size) {
            return true;
        }
        return false;
    }

    public int headIndex(){                     // Returns the index of head pointer.
        return head;
    }

    public int tailIndex() {                    // Returns the index of the tail pointer.
        return tail;
    }
}