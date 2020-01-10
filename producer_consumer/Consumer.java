import java.util.Random;
import java.util.Formatter;

public class Consumer extends java.lang.Thread  
{
	//Necessary variables and object declaration
    private Random randomWithSeed;
    private int count;
    private int number;
    private Buffer buff;
	
	public Consumer(Buffer buff, int count, int number) 
	{
		//Assign values to the varaibles
        this.count = count;
        this.number = number;
        this.buff = buff;
	}

	@Override
	public void run() 
	{
        for (int i = 0; i < count; i++) {
            // Create synchronized buffer access block.
            synchronized(buff) {
				while (buff.isEmpty()) {
					try {
						buff.wait();
					} catch (InterruptedException e) {}
                } 
                int index = buff.tailIndex();
                char element = (char) (buff.pop() + 64);
                String time = ProducerConsumer.getTime();
                System.out.printf("\033[0;4mConsumer\t%3d\033[0;0m consumed %c\tfrom\tindex %d at time %s\n", number, element, index, time);
                buff.notifyAll();
            }
		}
	}
}