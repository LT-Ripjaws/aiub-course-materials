import { BadRequestException, Injectable, NotFoundException } from '@nestjs/common';
import { randomUUID } from 'crypto';
import { CreateProfileDto } from './dto/create-profile.dto';

@Injectable()
export class ProfilesService {
    private profiles = [
        { id: randomUUID(), name: 'John Doe', description: 'A software developer' },
        { id: randomUUID(), name: 'Jane Smith', description: 'A graphic designer' },
        { id: randomUUID(), name: 'Bob Johnson', description: 'A web developer' },
    ];

    findAll() {
        if (this.profiles.length === 0) {
            throw new NotFoundException('No profiles found'); 
        }
        return this.profiles;
    }

    findOne(id: string) {
        const matchingProfile = this.profiles.find(profile => profile.id === id);
        if (!matchingProfile) {
           throw new NotFoundException('Profile not found');
        }
        return matchingProfile;
    }

    create(createProfileDto: CreateProfileDto) {
        const newProfile = 
        {   id: randomUUID(),
            name: createProfileDto.name,
            description: createProfileDto.description 
        };
        this.profiles.push(newProfile);
        return newProfile;
    }

    update(id: string, updateProfileDto: CreateProfileDto) {
        const matchingProfile = this.profiles.find(profile => profile.id === id);
        if (matchingProfile) {
            matchingProfile.name = updateProfileDto.name;
            matchingProfile.description = updateProfileDto.description;
            return matchingProfile;
        }
        throw new BadRequestException('Profile not created')    
    }

    delete(id: string){
        const index = this.profiles.findIndex(profile => profile.id === id);
        if (index !== -1) {
            this.profiles.splice(index, 1);
            return true;
        }
        return false;
    }
}
