/* M.Mehdi Naseri 9423115 */

class Queue
{
public:
	Queue(std::string fileName);
	Queue(Queue& Q); //Default constructor
	~Queue();
	void displayQueue();
	void enQueue(double element);
	double deQueue();
private:
	size_t capacity;
	size_t length;
	size_t readPoint;
	size_t writePoint;
	double* queue;
};
