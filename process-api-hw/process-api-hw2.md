## Question 2
One control the simulator gives you is the fork_percentage, controlled by the -f flag. The higher it is, the more likely the next action is a fork; the lower it is, the more likely the action is an exit.
Run the simulator with a large number of actions (e.g., -a 100)
and vary the fork_percentage from 0.1 to 0.9. What do you
think the resulting final process trees will look like as the percentage changes? Check your answer with -c.

### Answer
Increasing the fork percentage results in a more "bushy" process tree, with more processes forking off from each other. This is because the simulator is more likely to fork when the fork percentage is high, and less likely to exit. As a result, the tree grows wider and taller.

For example, with a fork percentage of 0.1, the tree is very sparse, with only a few processes forking off from each other. With a fork percentage of 0.9, the tree is very dense, with many processes forking off from each other.