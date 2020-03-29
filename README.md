# CollisionManager
A ground up step by step approach towards a C++ collision manager that can be later plugged into a larger larger project.

## Point2D
A class representing a geographical point

### Point2D operator +(Point2D movement)
Sum the coordinates of the point with another

### string toString();
Return a jsonified string version of the object

### string toString(string tabbing);
Return a jsonified string version of the object tabbed in line with the passed parameter eg: “\t\t”