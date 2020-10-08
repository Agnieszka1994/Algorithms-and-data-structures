using namespace std;

int longestPeak(vector<int> array) {
if (array.size() < 3) {
		return 0;
	}

	int greatestPeak = 0;
	int runningPeak = 0;
	//int pickPointer;
	for (int peak = 1; peak < array.size()-1; peak++){		

		if (array[peak] > array[peak - 1] && array[peak] > array[peak + 1]){
			runningPeak = 3;
			
			for(int leftPointer = peak - 1; leftPointer > 0; leftPointer--){
				
				if(array[leftPointer] > array[leftPointer-1]){
					runningPeak++;
				}
				else break;
			}
			
				for(int rightPointer = peak + 1; rightPointer < array.size()-1; rightPointer++){
					
				if(array[rightPointer] > array[rightPointer + 1]){
					runningPeak++;	 
				}
				else break;
			}
			if(runningPeak > greatestPeak){
			greatestPeak = runningPeak;
		}
			runningPeak = 0;
		}
		else
		continue;
	
	}
		 
  return greatestPeak;
}
