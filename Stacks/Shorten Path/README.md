# Shorten Path

This function takes in a non-empty string representing a valid Unix-shell path and returns a shortened version of that path.
A path is a notation that represents the location of a file or directory in a file system.
A path can be either an absolute path (is starts at the root directory) or a relative path (it starts at the current directory in a file system).\
\
A path is bound by the following rules: 
- The root directory is represented by a `/`. If a path starts with `/`, it's an absolute path; if it doesn't, it's a relative path. 
- The symbol `/` otherwise represents the directory separator (`foo/bar` means that the directory `bar` is inside the directory `foo`).
- The symbol `..` represents the parent directory. This means that accessing files or directories in `/foo/bar/..` is equivalent to `/foo`.
- The symbol `.` represents the current directory - it can be repeated sequentially without consequence. 

The shortened version of the path is equivalent to the original path - it points to the same file or directory.

### Sample input

```javascript
path = "/foo/../test/../test/../foo//bar/./baz"
```
### Sample output
```javascript
"/foo/bar/baz" // this path is equivalent to the input path
```
### Space and Time complexity

O(n) Space | O(n) Time - where n is the length of the path.