import java.lang.Exception;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;

class ProducerConsumer 
{
	public static void main(String[] args) 
	{
		/* Your code goes in here
		*
		*
		*
		---> When creating a thread of producer, the fourth argument to be passed should be seed+(i*10).
		---> where i is your looping variable whose value starts at 0 and goes till numberOfProducers - 1
		*
		*
		*
		*/
		if (args.length < 5) {
			System.out.println("Incorrect number of arguments.\nUSAGE: java ProducerConsumer [Buffer Size] [Number of Elements] [Number of Producers] [Number of Consumers] [Seed].");
			return;
		}
		// Assign arguments to variables.
		int bufferSize = Integer.parseInt(args[0]);
		int numElements = Integer.parseInt(args[1]);
		int numProducers = Integer.parseInt(args[2]);
		int numConsumers = Integer.parseInt(args[3]);
		int seed = Integer.parseInt(args[4]);
		//Create new Buffer.
		Buffer buff = new Buffer(bufferSize);
		// Create arrays to keep track of running threads.
		Producer[] prod = new Producer[numProducers];
		Consumer[] cons = new Consumer[numConsumers];
		// Generate the number of threads specified for Producer/Consumer.
		for (int i = 0; i < numProducers; i++) {
			prod[i] = new Producer(buff, (numElements/numProducers), i+1, (seed + i*10));
			prod[i].start();
		}
		for (int i = 0; i < numConsumers; i++) {
			cons[i] = new Consumer(buff, (numElements/numConsumers), i+1);
			cons[i].start();
		}
		// Wait for running threads to return.
		for (Producer prodi : prod) {
			try {
				prodi.join();
			} catch (InterruptedException e) {}
		}
		for (Consumer consi : cons) {
			try {
				consi.join();
			} catch (InterruptedException e) {}
		}
		// Required output.
		System.out.printf("\033[0;1mProducers\033[0;0m: Finished generating %d items\n", numElements);
		System.out.printf("\033[0;4mConsumers\033[0;0m: Finished generating %d items\n", numElements);
		return;
	}

	//Call this function from your producer or your conusmer to get the time stamp to be displayed
	public static String getTime()
	{
		Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-6));
		Instant time = Instant.now(offsetClock);
		String timeString = time.toString();
		timeString = timeString.replace('T', ' ');
		timeString = timeString.replace('Z', ' ');
		return(timeString);
	}
}