# CS 202 Semester Project Template
## Names: Jamie Lee, Nikhil Sharma
## Responsibilities: 

### Jamie:
#### File IO, Metadata
### Nikhil:
#### User Interface, Wav Processing, A little bit of File IO

## Description of Design:
##### The _design_ consisted of an interface template as a base class, with the several processors(Echo, Limiter, Noise gate, Normalization) acting as child classes which were also templates. We had to make the interface class a template to be able to template the child classes.
![alt text](https://github.com/[cpe-unr]/[group-project-pt24]/blob/[master]/uml.jpg?raw=true)
## Challenges:
##### The _challenges_ we encountered were mostly related to extracting the metadata and making templates out of the processors. Extracting metadata was difficult because it required tons of research. Making tempaltes was also very difficult as we had never made a template of an abstract base class, from which we derived child classes also of a template. **Not** having a third participating group mate also increased the difficulties. ***Though at the end, our whole programs works efficiently***
