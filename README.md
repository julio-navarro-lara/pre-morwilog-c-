# Pre-Morwilog
An old version of the Morwilog algorithm, written in C++, adapting the idea of Manhill algorithm.

## Context

This is a prototype version of what later became Morwilog, an ACO-based algorithm for attack identification and detection presented in my PhD Thesis "Modelization and identification of multi-step cyberattacks in sets of events". [Link to the PhD thesis manuscript](https://tel.archives-ouvertes.fr/tel-02315999/document).

At the origin of this code we find the Hommilière (Manhill) system, developed by Valigiani [Valigiani 2006] in his Ph.D. thesis. This system has been implemented in an e-learning platform, and its goal is to recommend personalized learning paths to each student. The recommendations depend on a mix between the past performance of the student and the results obtained by other students following similar paths. In the Manhill algorithm, the paths traversed by the artificial ants are built through the different lessons, which are arranged in the form of a graph [Gutiérrez 2007]. The level of deposed pheromones depends on how good are the results got by the student after each lesson, confirming or not the pertinence of that lesson in the educational evolution of the student. The most interesting contribution made by this algorithm is the interaction between the students and the ACO model. An artificial ant is created when a student connects to the platform. This notably differs from most of the existent implementations of ACO, where a fixed amount of artificial ants is created when the algorithm begins its execution. This brings the possibility of incorporating the variability of natural events, in this case the arrival of students, to the generation of the artificial ants. We have taken this idea in the conception of Morwilog, where the natural entity are the traces (or logs), that generate an artificial ant when they are collected by the system.

## Dependencies

This software require the NoSQL database WhiteDB. You can find it [here](http://whitedb.org/).

## References

[Valigiani 2006] Grégory Valigiani. Développement d’un paradigme d’optimisation par Hommilière
et application à l’enseignement assisté par ordinateur sur Internet. Ph.d. thesis, Université
du Littoral Côte d’Opale, 2006.

[Gutiérrez 2007] Sergio Gutiérrez, Grégory Valigiani, Pierre Collet and Carlos Delgado Kloos.
Adaptation of the ACO heuristic for sequencing learning activities. In Proceedings of the European
Conference on Technology Enhanced Learning (EC-TEL), pages 17–20, 2007.

