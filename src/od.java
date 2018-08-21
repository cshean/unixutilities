import java.util.*;
import java.io.*;

//enum for different types of output
//possibly have 1 represent octal, 2 hex etc.

class OD {
	public static void main(String[] args){
		//TODO: split this into a separate class
		boolean readFromStdin;
		ArrayList<String> filenames = new ArrayList<String>();
		for (int i = 0; i < args.length; ++i){
			if (args[i].equals("--help")) {
				System.out.println("Usage: od [OPTION]... [FILE]...");
			} else if (args[i].equals("--version")) {
				System.out.println("od (GNU coreutils) 8.25")
			//} else if (args[i].contains("-")){
			//   set enum to value
			// else {
			//assume it's a file
			//filenames.add(args[i]);
			//readFromStdin = false;
			}
		}

		//attempt to open file, or read from stdin
		//if (readFromStdin)
		//	Scanner reader = new Scanner();
		//	while(stdin)
		//		read
		//else
		//   open file
		//read in all bytes


		//process based on command

	}
}