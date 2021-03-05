# mod_sponsorship - Module template [![Build Status](https://cloud.drone.io/api/badges/Miithrandiir/mod_sponsorship/status.svg)](https://cloud.drone.io/Miithrandiir/mod_sponsorship)

This module allow you to create a sponsorship between two players. The effect will be buff applied and rate xp modified.
All of this can be modified in the sponsorship.conf


# How to install

1) Clone this project in `modules` folder

```bash
    cd somewhere/azerothcore/modules
    git clone https://github.com/Miithrandiir/sponsorship
```

2) Import all SQL files

All files are in `sql` directory execute in the order :
- Base
    - structure
    - production
- Updates (if exists)

Or you can use `include.sh` if provided

3) Re-run Cmake and launch your server


# Licence
This module is released under the [GNU AGPL 3.0 licence](https://www.gnu.org/licenses/agpl-3.0.md)