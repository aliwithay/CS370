import java.util.Random;
import java.util.Formatter;

public class Producer extends java.lang.Thread  
{
	//Necessary variables and object declaration
	private Random randomWithSeed;
	private int count;
	private int number;
	private Buffer buff;
	
	public Producer(Buffer buff, int count, int number,int seed) 
	{
		//Assign values to the varaibles
		randomWithSeed = new Random(seed);
		this.count = count;
		this.number = number;
		this.buff = buff;
	}

	@Override
	public void run()
	{
		/* Your code goes in here
		*
		*
		*
		--->To generate a value between 1 (inclusive) and 26 (inclusive) using the seeded random  number generator use the following code
		--->          int variable = randomWithSeed.nextInt(25) + 1;
		*
		*
		*
		*/
		for (int i = 0; i < count; i++) {
			// Generate random number with seed and convert to alphabet.
			int variable = randomWithSeed.nextInt(25) + 1;
			char element = (char) (variable + 64);
			// Create synchronized buffer access block.
			synchronized(buff) {
				// Pause thread while buffer is full.
				while (buff.isFull()) {
					try {
						buff.wait();
					} catch (InterruptedException e) {}
				}
				// Put variable on the buffer and get index.
				int index = buff.headIndex();
				buff.push(variable);
				//Get current time.
				String time = ProducerConsumer.getTime();
				// Print the required output and signal other threads.
				System.out.printf("\033[0;1mProducer\t%3d\033[0;0m inserted %c\tat\tindex %d at time %s\n", number, element, index, time);
				buff.notifyAll();
			}
		}
		return;
	}
}
